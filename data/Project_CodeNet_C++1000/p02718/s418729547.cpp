#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
int a[1003]; 
int m_itens = 0, total_votes = 0;
double a_d[1000];
double n_d, m_d, total_votes_d = 0.0;
int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

 
    cin >> n >> m;

    n_d = n*1.0;
    m_d = m*1.0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a_d[i] = a[i]*1.0;
        total_votes_d += a_d[i];
    }

    for (int i = 0; i < n; i++){
        if (a_d[i] >= (1.0/((4.0)*m_d))*total_votes_d){
            m_itens++;
        }
    }

    if (m_itens >= m){
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    
    return 0;
}
