#include<bits/stdc++.h>

std::vector<int> A;
int inf = 1001001001;


int parent(int key){
    int parent = key / 2;
    return parent;
}

int heapIncreaseKey(int i, int key){
    if(key < A[i]){
        return 0;
    }
    A[i] = key;
    int pa = parent(i);
    while(i > 1 && A[pa] < A[i]){
        std::swap(A[i], A[pa]);
        i = pa;
        pa = parent(i);
    }
}

void insert(int key){
    A.push_back(-inf);
    heapIncreaseKey(A.size()-1, key);
}


int maxHeapify(int i){
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;
    int n = A.size();
    if(l <= n && A[l] > A[i]){
        largest = l;
    }else{
        largest = i;
    }

    if(r <= n && A[r] > A[largest]){
        largest = r;
    }

    if(largest != i){
        int tmp;
        tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
    }else{
        return 0;
    }

    maxHeapify(largest);
}

int heapExtractMax(void){
    if(A.size() < 1){
        return -inf;
    }
    int max = A[1];
    A[1] = A[A.size()-1];
    A.pop_back();
    maxHeapify(1);
    return max;
}

int main(void){
    std::string str;
    int a;
    A.push_back(-inf);
    while(true){
        std::cin >> str;
        if(str == "insert"){
            std::cin >> a;
            insert(a);
        }else if(str == "extract"){
            int max = heapExtractMax();
            std::cout << max << std::endl;
        }else{
            break;
        }
    }
    
    return 0;
}
