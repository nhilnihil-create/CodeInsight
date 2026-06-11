#include <bits/stdc++.h>
using namespace std;

int main()  {
    float H,W,N;
    cin>>H>>W>>N;
    cout<<min(ceil(N/H),ceil(N/W));
    return 0;
}
