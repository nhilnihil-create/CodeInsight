#include<bits/stdc++.h>

std::vector<int> A;
int n;

int maxHeapify(int i){
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;
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

int main(void){
    std::cin >> n;
    A.resize(n+1);

    for(int i = 1; i <= n; i++){
        std::cin >> A[i];
    }

    for(int i = n/2; i > 0; i--){
        maxHeapify(i);
    }

    for(int i = 1; i <= n; i++){
        std::cout << " " << A[i];
    }
    std::cout << std::endl;
    
    return 0;
}
