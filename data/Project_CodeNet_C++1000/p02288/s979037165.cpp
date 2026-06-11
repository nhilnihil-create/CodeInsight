#include <iostream>
#include <cmath>

constexpr size_t MAX_HEAP_SIZE = 500000;;
int H[MAX_HEAP_SIZE + 1];

int parent(int i) { return i / 2; }

int left(int i) { return i * 2; }

int right(int i) { return i * 2 + 1; }

int MaxHeapify(int *H, int i, int heap_size) {
    int l = left(i);
    int r = right(i);
    int largest;
    if ((l <= heap_size) && (H[l]) > H[i]) {
        largest = l;
    }else{
        largest = i;
    }
    if ((r <= heap_size) && (H[r] > H[largest])) {
        largest = r;
    }
    if (largest != i) {
        std::swap(H[i], H[largest]);
        MaxHeapify(H, largest, heap_size);
    }
    return 0;
}

int BuildMaxHeap(int *H, int heap_size) {
    for (int i = heap_size / 2; i > 0; i--) {
        MaxHeapify(H, i, heap_size);
    }
    return 0;
}


int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> H[i];
    BuildMaxHeap(H, n);
    for (int i = 1; i <= n; i++) {
        std::cout << " ";
        std::cout << H[i];
    }
    std::cout << std::endl;
}
