#include <bits/stdc++.h>
#define ld long double
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector <ld> v;

    ld sum = 0;
    for(int i=0; i<n; i++){
        ld a;
        cin>>a;
        v.push_back(a);

        ld ans = (a+1)*1.00/2.00;
        if(i<k) sum+=ans;
    }

    ld fans = sum;
	for (int i=k; i<n; i++) {
		sum -= (v[i-k]+1)*1.00/2.00;
		sum += (v[i]+1)*1.00/2.00;

		fans = max(fans, sum);
	}
    cout<<fixed<<setprecision(10)<<fans<<endl;

    return 0;
}
