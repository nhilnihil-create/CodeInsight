#include <bits/stdc++.h>
#define fo(i,m,n) for(int i = m; i <= n; i++)
#define fod(i,m,n) for(int i = m; i >= n; i--)
#define fov(i,x) for(auto &i : x)
using namespace std;
typedef int64_t i64;
typedef pair<int,int> _ii;
int H,W,m;
vector <int> hang,cot;
vector <int> a,b;
map <_ii,int> A;
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> H >> W >> m;
    hang.resize(H+1,0);
    cot.resize(W+1,0);
    fo(i,1,m)
    {
        int _x,_y;
        cin >> _x >> _y;
        hang[_x]++;
        cot[_y]++;
        A[_ii(_x,_y)]++;
    }
    int p = *max_element(hang.begin(),hang.end());
    fo(i,1,H) if(hang[i] == p) a.push_back(i);
    p = *max_element(cot.begin(),cot.end());
    fo(i,1,W) if(cot[i] == p) b.push_back(i);
    int sum = hang[a[0]] + cot[b[0]];
    fov(i,a)
    {
        fov(j,b)
        {
            if(A.find(_ii(i,j)) == A.end())
            {
                cout << sum << '\n';
                return 0;
            }
        }
    }
    cout << sum-1 << '\n';
    return 0;
}
