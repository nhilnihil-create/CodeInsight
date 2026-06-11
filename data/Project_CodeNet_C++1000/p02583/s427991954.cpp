#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0); //Don't delete this line!
    long long n;
    cin >> n;
    vector<long long> v;
    while(n--){
        long long l;
        cin >> l;
        v.push_back(l);
    }
    long long pairs=0;
    sort(v.begin(),v.end());
    vector<long long>::iterator up;
    for(long long i=0;i<v.size()-1;i++){
        for(long long j=i+1;j<v.size();j++){
            if(v[i]!=v[j]){
            long long add = (v[i]+v[j])-1;
            up = upper_bound(v.begin(),v.end(),add);
            pairs += up - lower_bound(v.begin(),v.end(),(v[j]+1));
            //cout << i << " " << j << " " << pairs << '\n';
            }
        }
    }
    cout << pairs;
}
