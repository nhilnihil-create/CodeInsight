#include <bits/stdc++.h>
using namespace std;
vector<int> A;
int cnt;
void insertionSort(int n,int g){
    int j,v;
    for (int i = g; i< n;i++){
        v = A[i];
        j = i - g;
        while (j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
    
}
void shellSort(int n){
    cnt = 0;
    int siz=0;
    vector<int> G;
    while(1){
        siz=siz*3+1;
        if(siz>=n&&siz!=1)break;
        G.push_back(siz);
    }
    cout << G.size() <<endl;
    for(int i =G.size()-1;i>=0;i--){
        insertionSort(n, G[i]);cout <<G[i] <<((i!=0)?" ":"\n");
    }
}

int main(void){
    int n,t;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        A.push_back(t);
    }
    shellSort(n);
    cout << cnt<<endl;
    for(int i:A){
        cout << i<<endl;
    }
}