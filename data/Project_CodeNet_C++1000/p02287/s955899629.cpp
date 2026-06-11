#include <iostream>
using namespace std;

int parent(int i){
    return i/2;
}

int left(int i){
    return i*2+1;
}

int right(int i){
    return i*2+2;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    int H[n];
    for(int i=0;i<n;i++){
       cin >> H[i];
    }
    
    for(int i=0;i<n;i++){
        cout << "node " << i+1 << ": ";
        cout << "key = " << H[i] << ", ";
        if(i!=0 && 0<=parent(i) &&parent(i)<n)
            cout << "parent key = " << H[parent(i-1)] << ", ";
        if(0<=left(i) && left(i)<n)
            cout << "left key = " << H[left(i)] << ", ";
        if(0<=right(i) && right(i)<n)
            cout << "right key = " << H[right(i)] << ", ";
        cout << endl;
    }
    return 0;
}