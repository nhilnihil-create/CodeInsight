#include <bits/stdc++.h>
using namespace std;
//using long long = long long;

#define MAX 100000

struct Node{int key,parent,left,right;};

int parent(int i){return i/2;}
int left(int i){return 2 * i;}
int right(int i){return 2 * i + 1;}

int main(){
    long long n;
    int i;
    long long A[MAX+1];
    cin >> n;
    for(long long i = 0; i < n; i++){
        cin >> A[i+1];
    }
    for(long long i = 0; i < n; i++){
        cout << "node " << i+1 << ": key = " << A[i+1] << ", ";
        if(parent(i+1) > 0) cout << "parent key = " << A[parent(i+1)] << ", ";
        if(left(i+1) <= n) cout << "left key = " << A[left(i+1)] << ", ";
        if(right(i+1) <= n) cout << "right key = " << A[right(i+1)] << ", "; 
        cout << endl;
    }

    return 0;
}
