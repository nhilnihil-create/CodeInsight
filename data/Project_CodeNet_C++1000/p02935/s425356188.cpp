#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    int n;
    cin>>n;
    priority_queue<float, vector<float>, greater<float>>pq;
    for(int i=0;i<n;i++){
        float f;
        cin>>f;
        pq.push(f);
    }
    while(pq.size()!=1){
        float f1=pq.top();
        pq.pop();
        float f2=pq.top();
        pq.pop();
        pq.push(float((f1+f2)/2));
    }
    cout<<pq.top();
}

