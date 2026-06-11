#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    set <int> s;
    int N;
    cin >> N;

    int a;
    for(int i=0; i<N; i++)
    {
        cin >> a;
        s.insert(a);
    }

    if(s.size() != N)
    {
        cout << "NO" << endl;
    }

    else
    {
        cout << "YES" << endl;
    }

}
