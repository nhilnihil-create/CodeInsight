#include <iostream>
#include <vector>
#include <climits>

class Nodes;

class Node {
public:
    Node(int n) : id(n), cost(INT_MAX) { }
    void addEdge(int to, int cost) { edgesTo.push_back(to); edgesCost.push_back(cost); }
    int getId() { return id; }
    int getCost() { return cost; }
    void setCost(int alt) { cost = alt; }
    void print() { std::cout << id << " " << cost << std::endl; }
    void printAll() {
        std::cout << id << " " << cost;
        for (std::vector<int>::iterator itr = edgesTo.begin(), itr2 = edgesCost.begin();  itr != edgesTo.end(); ++itr, ++itr2) {
            std::cout << " " << *itr << " " << *itr2;
        }
        std::cout << std::endl;
    }
    void updatesCost(Nodes* nodes);
private:
    int id;
    std::vector<int> edgesTo;
    std::vector<int> edgesCost;
    int cost;
};

class Nodes {
public:
    void readFromIn() {
        int size;
        std::cin >> size;
        for (int i=0; i<size; ++i) {
            int id;
            int sizeOfEdges;
            std::cin >> id >> sizeOfEdges;
            Node *node = new Node(id);
            for (int j=0; j<sizeOfEdges; ++j) {
                int to;
                int cost;
                std::cin >> to >> cost;
                node->addEdge(to, cost);
                //std::cout << to << cost << std::endl;
            }
            nodes.push_back(node);
        }
        nodes[0]->setCost(0);
    }
    std::vector<Node*>::iterator findNodeWithTheLeastDistance(std::vector<Node*> &queue) {
        std::vector<Node*>::iterator min=queue.begin();
        for (std::vector<Node*>::iterator itr=queue.begin()+1; itr != queue.end(); ++itr) {
            if ((*min)->getCost() > (*itr)->getCost()) {
                min = itr;
            }
        }
        return min;
    }
    void dijkstrasAlgorithm() {
        std::vector<Node*> queue(nodes);

        while (!queue.empty()) {
            std::vector<Node*>::iterator u = findNodeWithTheLeastDistance(queue);
            int n = (*u)->getId();
            //std::cout << "**" << n << std::endl;
            queue.erase(u);

            getNode(n)->updatesCost(this);
        }
    }
    void print() {
        for (std::vector<Node*>::iterator itr=nodes.begin(); itr != nodes.end(); ++itr) {
            (*itr)->print();
        }
    }
    Node* getNode(int n) {
        return nodes[n];
    }
private:
    std::vector<Node*> nodes;
};

void Node::updatesCost(Nodes* nodes) {
    for (std::vector<int>::iterator itr = edgesTo.begin(), itr2 = edgesCost.begin();  itr != edgesTo.end(); ++itr, ++itr2) {
    Node* v = nodes->getNode(*itr);
    int alt = cost + *itr2;
    if (alt < v->getCost()) {
        v->setCost(alt);
    }
    //nodes->print();
}
    /*
for (i=0; i<nodes[u]->sizeOfEdges; ++i) {
    int v = nodes[u]->edgesTo[i];
    int alt = nodes[u]->cost + nodes[u]->edgesCost[i];
    if (alt < nodes[v]->cost) {
        nodes[v]->cost = alt;
    }
}
*/
}

int main(int argc, char *argv[])
{
    Nodes nodes;

    nodes.readFromIn();
    nodes.dijkstrasAlgorithm();
    nodes.print();
    return 0;
}