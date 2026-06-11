#include<bits/stdc++.h>
using namespace std;
set<int>st;
int num_of_pf(int n)
{
    int cnt = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            while(n % i == 0)
                n /= i;
            st.insert(i);
        }
    }
    if (n > 1)
        st.insert(n), cnt++;
    return cnt;
}

int v[1000005];
int main()
{
    int s_c;
    int n;
    cin >> n;
    int cnt = 0;
    set<int> s;
    for(int i=1;i<=n;i++)
    {
        cin >> v[i];
        if (i == 1)
            s_c = v[i];
        s_c = __gcd(s_c, v[i]);
    }
    if (s_c != 1)
    {
        cout << "not coprime" << endl;
        return 0;
    }
    int p_c = 1;
    for(int i=1;i<=n;i++)
    {
        cnt += num_of_pf(v[i]);
        if (cnt !=st.size())
        {
            p_c = 0;
            break;
        }
    }
    if (p_c)
        cout << "pairwise coprime" << endl;
    else
        cout << "setwise coprime" << endl;

}
