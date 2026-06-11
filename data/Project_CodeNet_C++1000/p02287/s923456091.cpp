#include <iostream>
#include <cstdio>

constexpr int MAX_SIZE = 250 + 1;
int heap[MAX_SIZE];

int parent(int i) {return i / 2;}
int left(int i) {return 2 * i;}
int right(int i) {return 2 * i + 1;}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> heap[i];
    }

    for(int i = 1; i <= n; i++) {
        std::printf("node %d: key = %d, ", i, heap[i]);
        if (parent(i) > 0) std::printf("parent key = %d, ", heap[parent(i)]);
        if (left(i) <= n) std::printf("left key = %d, ", heap[left(i)]);
        if (right(i) <= n) std::printf("right key = %d, ", heap[right(i)]);
        std::cout << std::endl;
    }


}
