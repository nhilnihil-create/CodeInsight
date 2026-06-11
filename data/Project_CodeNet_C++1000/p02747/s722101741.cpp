#include <bits/stdc++.h>
#define pi acos(-1)
#define maxn 200001
using namespace std;
typedef long long ll;
const int mx=100005;
//void init(int node, int b, int e)
//{
//    if (b == e) {
//        tree[node] = a[b];
//        return;
//    }
//    int Left = node * 2;
//    int Right = node * 2 + 1;
//    int mid = (b + e) / 2;
//    init(Left, b, mid);
//    init(Right, mid + 1, e);
//    tree[node] = __gcd(tree[Left],tree[Right]);
//}
//int query(int node, int b, int e, int i, int j)
//{
//    if (i > e || j < b)
//        return 0;
//    if (b >= i && e <= j)
//        return tree[node];
//    int Left = node * 2;
//    int Right = node * 2 + 1;
//    int mid = (b + e) / 2;
//    int p1 = query(Left, b, mid, i, j);
//    int p2 = query(Right, mid + 1, e, i, j);
//    return __gcd(p1,p2);
//}
//void update(int node, int b, int e, int i, int newvalue)
//{
//    if (i > e || i < b)
//        return;
//    if (b >= i && e <= i) {
//        tree[node] = newvalue;
//        return;
//    }
//    int Left = node * 2;
//    int Right = node * 2 + 1;
//    int mid = (b + e) / 2;
//    update(Left, b, mid, i, newvalue);
//    update(Right, mid + 1, e, i, newvalue);
//    tree[node] = __gcd(tree[Left] , tree[Right]);
//}

int main(){

    string s;
    cin>>s;
    int cnt=0;
    for(int i=1;i<s.size();i++){
        if(s[i-1]=='h' && s[i]=='i')cnt+=2;
    }
    if(cnt==s.size()){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}
