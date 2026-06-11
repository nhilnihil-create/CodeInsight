#include <iostream>
#include <string>
#include <vector>


class Node
{
private:
    int _id;
    int _parent;
    int _depth;
    std::vector<int> _children;

public:
    Node() {
        this->_id = -1;
        this->_parent = -1;
        this->_depth = 0;
    }

    Node(int id) {
        this->_id = id;
        this->_parent = -1;
        this->_depth = 0;
    }

    ~Node() {
        ;
    }

    const int& id() const {
        return this->_id;
    }

    int& id() {
        return this->_id;
    }

    const int& parent() const {
        return this->_parent;
    }

    int& parent() {
        return this->_parent;
    }

    const int& depth() const {
        return this->_depth;
    }

    int& depth() {
        return this->_depth;
    }

    const std::vector<int>& children() const {
        return this->_children;
    }

    void set_child(int childid) {
        this->_children.push_back(childid);
    }

    std::string type() {
        if (this->_parent == -1)
            return "root";
        else if (this->_children.empty())
            return "leaf";
        else
            return "internal node";
    }

};

std::vector<Node> nodelist;

void print(Node node) {
    std::cout << "node " << node.id() << ": parent = " << node.parent() << ", depth = " << node.depth() << ", " << node.type() << ", [";
    if (node.children().size() != 0) {
        for (int i = 0; i < node.children().size() - 1; i++) {
            std::cout << node.children()[i] << ", ";
        }
        std::cout << node.children()[node.children().size() - 1] << "]" << std::endl;
    } else {
        std::cout << "]" << std::endl;
    }
}

void setdepth(Node& node, int curdepth)
{
    node.depth() = curdepth;

    for (int childid : node.children())
        setdepth(nodelist[childid], curdepth + 1);
}

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    nodelist.resize(n);
    int id;
    int child_id;
    int k;
    for (int i = 0; i < n; i++) {
        nodelist[i].id() = i;

        std::cin >> id >> k;
        for (int j = 0; j < k; j++) {
            // set children
            std::cin >> child_id;
            nodelist[id].set_child(child_id);

            // set parent
            nodelist[child_id].parent() = id;
        }
    }

    // calculate depth
    int rootid = 0;
    for (int i = 0; i < n; i++) {
        if (nodelist[i].parent() == -1) {
            rootid = i;
            break;
        }
    }
    setdepth(nodelist[rootid], 0);

    // output
    for (int i = 0; i < n; i++) {
        print(nodelist[i]);
    }

    return 0;
}