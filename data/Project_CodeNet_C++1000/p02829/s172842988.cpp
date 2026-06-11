#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int main() {
    set <int> st;
    int x, y;
    scanf("%d %d", &x, &y);
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.erase(x);
    st.erase(y);
    printf("%d\n", *st.begin());
    return 0;
}
