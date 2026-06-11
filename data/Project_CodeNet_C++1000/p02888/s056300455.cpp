#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=0;i<n;i++)
#define endl   "\n"
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    f(n)cin>>v[i];
    sort(v.begin(),v.end());
    int answer=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum=v[i]+v[j];
            //cout<<sum<<endl;
            auto it=lower_bound(v.begin(),v.end(),sum);

            int index=it-v.begin();
            //cout<<index<<endl;


                int p=index-j-1;

               //cout<<p<<endl;
                answer+=p;





        }



    }
    cout<<answer<<endl;







}