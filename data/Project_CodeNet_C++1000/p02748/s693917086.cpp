#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,M;
    cin>>A>>B>>M;
    vector<int> a(A,0);
    vector<int> b(B,0);
    vector<int> c(M,0);
    vector<int> x(M,0);
    vector<int> y(M,0);
    int min_a;
    int min_b;
    int min_mix=INT_MAX;
    for (size_t i = 0; i < A; i++)
    {
        cin>>a[i];
    }
    for (size_t i = 0; i < B; i++)
    {
        cin>>b[i];
    }
    min_a = *std::min_element(a.begin(), a.end());
    min_b = *std::min_element(b.begin(), b.end());
    
    for (size_t i = 0; i < M; i++)
    {
        cin>>x[i]>>y[i]>>c[i];
        min_mix = std::min(min_mix,a[x[i]-1]+b[y[i]-1]-c[i]);
        /* code */
    }
    cout << std::min(min_a+min_b, min_mix)<<endl;
    return 0;
}