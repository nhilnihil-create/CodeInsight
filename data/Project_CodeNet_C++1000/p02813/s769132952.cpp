#include<bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main()
{
    int n,i;
    cin>>n;

    vector <int> p(n);

    vector <int> q(n);

    rep(i,n) cin>>p[i];
    rep(i,n) cin>>q[i];

    vector <int> temp=p;

    sort(temp.begin(),temp.end());

    int count1=0,count2=0,ans1=0,ans2=0;

    do{
        count1++;
        count2++;

        if(temp==p){
            ans1=count1;
        }
        if(temp==q){
            ans2=count2;
        }
    }while(next_permutation(temp.begin(),temp.end()));


    cout<<abs(ans1-ans2)<<endl;




return 0;
}
