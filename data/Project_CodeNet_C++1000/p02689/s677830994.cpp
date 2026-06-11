#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)

void textIO()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

}

vector<long long> arr(1e5+5);

int main()
{
    textIO();
    fastIO();

    set<long long> st;
    long long n, m;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<m;i++){
        long long a, b;
        cin >> a >> b;

        if(arr[a] == arr[b]){
            st.insert(a);
            st.insert(b);
        }
        else if(arr[a] < arr[b]){
            st.insert(a);
        }
        else{
            st.insert(b);
        }

    }

    cout << n-st.size() << '\n';

    return 0;
}
