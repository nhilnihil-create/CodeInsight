#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define MAX 2000000

int h = 0;
vector<int> heap(MAX); 


void maxHeapify(int i){
    int left_index = 2 * i;
    int right_index = 2 * i + 1;

    int largest_index = i;

    if(left_index <= h && heap.at(left_index) > heap.at(i)){
        largest_index = left_index;
    }
    if(right_index <= h && heap.at(right_index) > heap.at(largest_index)){
        largest_index = right_index;
    }

    if(largest_index != i){
        // インデックスiの中身とインデックスlargest_indexの中身をswap
        int tmp = heap.at(i);
        heap.at(i) = heap.at(largest_index);
        heap.at(largest_index) = tmp;
        // swapした結果、largest_indexでのヒープが崩れる可能性があるので再びheapify
        maxHeapify(largest_index);
    }

}

void buildMaxHeap(){
    for(int i = h/2; i > 0; i--){
        maxHeapify(i);
    }
}

void increaseKey(int index){
    int parent_index = index / 2;
    while(parent_index > 0 && (heap.at(index) > heap.at(parent_index))){
        int tmp = heap.at(parent_index);
        heap.at(parent_index) = heap.at(index);
        heap.at(index) = tmp;

        tmp = index;
        index = parent_index;
        parent_index = index/2;
    }
}

int main(){
    while(true){
        string command;
        cin >> command;

        if(command == "insert"){
            h++;
            int n;
            scanf("%d", &n);
            heap.at(h) = n;
            increaseKey(h);

        }else if(command == "extract"){
            cout << heap.at(1) << endl;
            heap.at(1) = heap.at(h);
            h--;
            maxHeapify(1);

        }else if(command == "end"){
            break;
        }
    }
    
    // for(int i = 1; i < h + 1; i++){
    //     cout << " " << heap.at(i);
    // }
    // cout << endl;

}
