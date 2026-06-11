#include<bits/stdc++.h>
using namespace std;
vector<int> sum;
vector<int> arr;
// mid -> 次数
//   i -> 一次几个
bool ok(int mid,int i){
	int id = lower_bound(arr.begin(),arr.end(),mid) - arr.begin();
    int left = id-1<0 ? 0: sum[id-1];
	int ct = arr.size() - id;
    ct += left/mid;
	if(ct>=i){
		return true;
	}
	return false;
}

void solve(int i){
	int l = 0;
	int r = arr.size()/i;
    
	while(l < r){
        //cout<<l<<" "<<r<<endl;
		if(r == l+1){
			if(ok(r,i)){
				l = r;
				break;
			}else{
              	r = l;
                break;
            }
		}

		int mid = (r+l)/2;
		if(ok(mid,i)){
			l = mid;
		}else{
			r = mid - 1;
		}
	}

	cout<<l<<endl;
	return ;
}

int main(){
	int n;cin>>n;
	arr = vector<int>(n);
	for(int i=0;i<n;++i){
		int curr;cin>>curr;
		arr[curr-1]++;
	}
	sort(arr.begin(),arr.end());
	sum = arr;
	for(int i=1;i<n;++i){
		sum[i] += sum[i-1];
	}
  //for(auto i:arr)cout<<i<<" ";cout<<endl;
  //for(auto i:sum)cout<<i<<" ";cout<<endl;
	for(int i=1;i<=n;++i){
		solve(i);
	}
	return 0;
}