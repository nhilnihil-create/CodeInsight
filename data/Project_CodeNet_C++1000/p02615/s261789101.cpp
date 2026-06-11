#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

struct Node{
    int l, r, comfort;
    Node(int left, int right, int cc):l(left),r(right),comfort(cc){}
};

struct CompareComfort{
    bool operator()(const Node& a, const Node& b){
        return a.comfort < b.comfort;
    }
};

int n;
vector<int> arr;
priority_queue<Node, vector<Node>, CompareComfort> PQ;

int main(){
    AC
    cin>>n;
    arr.resize(n);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr[i] = x;
    }

    sort(arr.rbegin(), arr.rend());
    PQ.push(Node(arr[0], arr[1], min(arr[0],arr[1])));
    PQ.push(Node(arr[0], arr[1], min(arr[0],arr[1])));
    ll ans = arr[0];
    for(int i=2; i<n; i++){
        Node n = PQ.top();
        PQ.pop();
        ans+=n.comfort;
        PQ.push(Node(n.l, arr[i], min(n.l, arr[i])));
        PQ.push(Node(n.r, arr[i], min(n.r, arr[i])));
    }
    cout<<ans<<endl;
}