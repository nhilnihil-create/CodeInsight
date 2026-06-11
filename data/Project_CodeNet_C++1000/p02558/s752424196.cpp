#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<climits>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
using namespace std;

class Set{
    vector<int> parent;
    public:

    Set(int n)
    {
        for(int i = 0;i<n;i++)
        {
            parent.push_back(i);
        }
    }

    int getSuperParent(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x] = getSuperParent(parent[x]);
    }

    void join(int a, int b)
    {
        a = getSuperParent(a);
        b = getSuperParent(b);
        if(a!=b)
        {
            parent[b] = a;
        }
    }

    void ifConnected(int a, int b)
    {
        a = getSuperParent(a);
        b = getSuperParent(b);
        if(a==b)
        {
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
};


int main()
{
    int n,k;
    cin>>n>>k;
    Set s(n);

    int op,a,b;
    for(int i = 0;i<k;i++)
    {
        cin>>op>>a>>b;
        if(!op)
        {
            s.join(a,b);
        }
        else{
            s.ifConnected(a,b);
        }
    }
    return 0;
}
