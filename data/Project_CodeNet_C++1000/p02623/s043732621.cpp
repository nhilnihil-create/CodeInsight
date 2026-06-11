#include <bits/stdc++.h>
#define pi 3.14159
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
template<class T> using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
int main()
{
long long n,m,array1[200005],array2[200005],k,i,counter=0,maxi=0,sum=0;
ordered_set<long long>s,s2;
cin>>n>>m>>k;
for(i=0;i<n;++i){
    cin>>array1[i];
    sum+=array1[i];
    s2.insert(sum);
}
sum=0;
for(i=0;i<m;++i){
    cin>>array2[i];
    sum+=array2[i];
    s.insert(sum);
}
sum=0;
for(i=0;i<n;++i){
    counter=i+1;
    sum+=array1[i];
    if(sum>k){
        break;
    }
    counter+=s.order_of_key(k-sum);
    if(s.find(k-sum)!=s.end()){
        counter++;
    }
    maxi=max(maxi,counter);
}
sum=0;
for(i=0;i<m;++i){
    counter=i+1;
    sum+=array2[i];
    if(sum>k){
        break;
    }
    counter+=s2.order_of_key(k-sum);
    if(s2.find(k-sum)!=s2.end()){
        counter++;
    }
    maxi=max(maxi,counter);
}
cout<<maxi<<endl;

    return 0;
}
