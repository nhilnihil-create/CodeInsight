
#include <bits/stdc++.h>

using namespace std;

#define MAX 2000000
int HSIZE = 0;
int tree[MAX];
void heapIncreaseKey(int i, int key) {
    if(key < tree[i]) {
        cout << "error: new key is smaller than curren key" << endl;
        return;
    }
    tree[i] = key;
    while(i > 1 && tree[i / 2] < tree[i]) {
        swap(tree[i / 2], tree[i]);
        i = i / 2;
    }
}
void insert(int key) {
    HSIZE++;
    tree[HSIZE] = -2147483648;
    heapIncreaseKey(HSIZE, key);
}
void maxHeapify(int idx) {
    int l = 2 * idx;
    int r = l + 1;
    int largest;
    if(l <= HSIZE && tree[l] > tree[idx]) {
        largest = l;
    } else {
        largest = idx;
    }

    if(r <= HSIZE && tree[r] > tree[largest]) {
        largest = r;
    }

    if(largest != idx) {
        swap(tree[idx], tree[largest]);
        maxHeapify(largest);
    }
}

int heapExtractMax() {
    // error handling
    if(HSIZE < 1) {
        cout << "error: heap under flow" << endl;
        return -1;
    }
    // take root. then override root with tree[HSIZE]
    int max = tree[1];
	tree[1] = tree[HSIZE--];
    maxHeapify(1);
    return max;
}

int main() {
    int key;
    char com[10];
    while(1) {
        scanf("%s", com);
        if(string(com) == "end") {
            break;
        } else if(string(com) == "insert") {
            scanf("%d", &key);
            insert(key);
        } else if(string(com) == "extract") {
            printf("%d\n", heapExtractMax());
        }
    }
}
