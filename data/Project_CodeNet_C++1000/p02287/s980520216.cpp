#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;
#define qaz 20000

int m;
int parent(int i){
    return i/2;
    }

int left(int i){
    return 2*i;
    
}
int right(int i){
     return 2*i+1;
}

int a[qaz];
int main(void){
    cin>>m;
    for(int j=1;j<=m;j++){
        cin>>a[j];
    }
    
    for(int i=1;i<=m;i++){
        cout<<"node "<<i<<": key = "<<a[i]<<", ";
        if(parent(i)>=1)cout<<"parent key = "<<a[parent(i)]<<", ";
        if(left(i)<=m) cout<<"left key = "<<a[left(i)]<<", ";
        if(right(i)<=m) cout<<"right key = "<<a[right(i)]<<", ";
        cout<<endl;
    }

    return 0;
}


