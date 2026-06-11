#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    string output;

    while (cin >> n >> m){
        output = to_string(n+m);
        cout << output.size()<<endl;
    }

    return 0;
}