/*http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_D&lang=jp*/
#include <iostream>
#include <algorithm>

using namespace std;

void insertionSort(int *a,int n,int g,int *cnt){
    for(int i=g;i<n;i++){
        int v=a[i];
        int j=i-g;
        while(-1<j && v<a[j]){
            a[j+g]=a[j];
            j-=g;
            (*cnt)++;
        }
        a[j+g]=v;
    }
}

void shellSort(int *a,int n){
    int cnt=0;
    vector<int> g(1,1);

    while(3*g.back()+1<=n){
        g.push_back(3*g.back()+1);
    }
    reverse(begin(g),end(g));
    cout<<g.size()<<endl;
    vector<int>::iterator it=g.begin();
    cout<<*it;
    it++;
    while(it!=g.end()){
        cout<<" "<<*it;
        it++;
    }
    cout<<endl;
    for(int i:g){
        insertionSort(a,n,i,&cnt);
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}

int main(){
    int n;
    int a[1000000];

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    shellSort(a,n);
    return 0;
}