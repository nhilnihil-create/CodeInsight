#include<iostream>
#include<vector>
using namespace std;
int A[1000000];
int n, cnt;
vector<int> G;
void is(int g){
    for(int i=g;i<n;++i){
        int v = A[i];
        int j = i-g;
        while(j>=0 && A[j]>v){
            A[j+g] = A[j];
            j -= g;
            cnt++; 
        }
        A[j+g] = v;
    }
}
void ss(){
    for(int h=1;h<=n;h=3*h+1) G.push_back(h);
    for(int i=G.size()-1;i>=0;--i) is(G[i]);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i) cin>>A[i];
    ss();
    cout<<G.size()<<endl;
    for(int i=G.size()-1;i>=0;--i) cout<<G[i]<<(i?" ":"");
    cout<<endl;
    cout<<cnt<<endl;
    for(int i=0;i<n;++i) cout<<A[i]<<endl;
}