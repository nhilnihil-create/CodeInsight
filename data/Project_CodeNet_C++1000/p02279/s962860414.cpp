#include <cstdio>
#include <iostream>
#include <list>
#include <vector>

class Node {
    public:
        int id;
        int depth;
        int parent_id;
        std::list<int> children;
        Node() {}
};

void validate_depth(std::vector<Node>& data, int id, int depth)
{
    data[id].depth = depth;
    for(auto iter = data[id].children.begin(); iter != data[id].children.end(); iter++) {
        validate_depth(data, *iter, depth + 1);
    }
}

void show_nodes(std::vector<Node>& data)
{
    for(int i = 0; i < data.size(); i++) {
        printf("node %d: parent = %d, depth = %d, ", i, data[i].parent_id, data[i].depth);
        if(data[i].parent_id == -1) {
            printf("root, ");
        } else if(data[i].children.empty()) {
            printf("leaf, ");
        } else {
            printf("internal node, ");
        }
        putchar('[');
        for(auto iter = data[i].children.begin(); iter != data[i].children.end(); iter++) {
            if(iter == data[i].children.begin()) {
                printf("%d", *iter);
            } else {
                printf(", %d", *iter);
            }
        }
        puts("]");
    }
}

int search_root(std::vector<Node>& data, int current_id)
{
    if(data[current_id].parent_id == -1) {
        return current_id;
    } else {
        return search_root(data, data[current_id].parent_id);
    }
}

int main()
{
    int input_size;
    std::cin >> input_size;
    std::vector<Node> data(input_size);
    for(int i = 0; i < data.size(); i++) {
        data[i].parent_id = -1;
    }
    for(int i = 0; i < data.size(); i++) {
        int id;
        std::cin >> id;
        int num_of_children;
        std::cin >> num_of_children;
        for(int j = 0; j < num_of_children; j++) {
            int child_id;
            std::cin >> child_id;
            data[id].children.push_back(child_id);
            data[child_id].parent_id = id;
        }
    }

    int root_id = search_root(data, 0);

    validate_depth(data, root_id, 0);
    show_nodes(data);
    return 0;
}