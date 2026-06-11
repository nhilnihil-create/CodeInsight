#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> p(n,k-q);
    for(int i=0;i<q;i++){
        int a;
        cin>>a;
        a--;
        p[a]++;
    }
    for(int i=0;i<n;i++){
        if(p[i]>0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
