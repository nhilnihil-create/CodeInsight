#include<bits/stdc++.h>
using namespace std;


vector<int> ar[200001];

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        ar[a].push_back(i);
    }
    for(int i=1;i<=n;i++){
            int sum = 0;
         for(auto it = ar[i].begin();it!=ar[i].end();it++){
            sum++;
         }
        cout<<sum <<endl;
    }


}
