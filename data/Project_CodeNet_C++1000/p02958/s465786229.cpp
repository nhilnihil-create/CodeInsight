#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> given(n);
    for(int i=0;i<n;i++)
        cin>>given.at(i);
    vector<int> sorted(given);
    sort(sorted.begin(),sorted.end());
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(given.at(i)!=sorted.at(i))
            count++;
    }
    if(count > 2)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;

}
