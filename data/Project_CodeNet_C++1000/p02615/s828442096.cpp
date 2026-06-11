#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;

int main(){
    int n;
    scanf("%d",&n);
    vi num;
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        num.pb(temp);
    }
    sort(all(num),greater<int>());
    //for(auto i = num.begin();i!=num.end();i++){
    //    printf("%d ",*i);
    //}
    printf("\n");
    ll res=0;
    int index=0;
    int count=0;
    res+=num[index];
    index++;
    for(int i=3;i<=n;i++){
        if(count==2){
            index++;
            count=0;
        }
        res+=num[index];
        count++;
    }
    printf("%lld\n",res);
}





