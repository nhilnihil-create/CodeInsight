
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    string ans;
    string A,B;
    cin >> A >> B;
    for(int i=0; i<N; i++)
    {
        ans+=A.at(i);
        ans+=B.at(i);
    }
    cout << ans <<endl;

}