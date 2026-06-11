#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;
using ll=long long;


/*
    priority-queue
    ->要素をqueueに追加した瞬間に、中の値を自動的にsortする。
    <<宣言>>
    priority-queue<型> 変数名;(降順)
    priority-queue<型,vector<型>,greator<型>> 変数名；（昇順）

    要素の追加:変数名.push(値);
    要素の取得:変数名.top();
    要素の削除:変数名.pop();
    要素数の取得:変数名.size();
    からかどうかの判定:変数名.empty();

*/

int main()
{
    int n,m;
    cin >> n >> m;
    priority_queue<ll> s;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        s.push(a);
    }
    for(int i=0;i<m;i++)
    {
        int x;
        x=s.top();
        s.pop();
        x/=2;
        s.push(x);
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=s.top();
        s.pop();
    }
    cout << ans << endl;
    return(0);
}