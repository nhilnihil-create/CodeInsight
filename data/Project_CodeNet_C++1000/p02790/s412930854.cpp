#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin>> a >> b;

    if(a > b)
        swap(a, b);

    vector<int> ans;

    ans.insert(ans.begin(),b,a);

    for(int i = 0; i <ans.size(); i++)
        cout<< ans[i];
    
    return 0;
}
