#include<bits/stdc++.h>
using namespace  std;

int main(){
    int n; cin >> n;
    vector<int> a;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int tmp; cin >> tmp;
        a.push_back(tmp);
        if(mp.count(tmp))
            mp[tmp]++;
        else
            mp[tmp] = 1;
    }

    bool flg=false;

    if(mp.size()==1){
        if(mp.count(0)) 
            flg = true;
    }else if(mp.size()==2){
        int b[2];
        int d[2];
        int c = 0;
        for (auto i : mp)
		{
			b[c] = i.second;
			d[c] = i.first;
			++c;
		}
 
		sort(b, b + 2);
		sort(d, d+ 2);
		if (n % 3 == 0)
		{
			if (mp[d[1]] == mp[d[0]] * 2 && d[0] == 0) flg = true;
		}
    }else if(mp.size()==3){
        int b[3];
        int d[3];
        int c = 0;
        for(auto i : mp){
            b[c] = i.second;
            d[c] = i.first;
            c++;
        }
        sort(b, b+3);
        if(n%3==0 && ((d[0]^d[1])==d[2]) && ((d[0]^d[2])==d[1]) && ((d[1]^d[2])==d[0])){
            if(b[0] == b[1] && b[1] == b[2] && b[0] == b[2]) flg = true;
        }
    }

    cout <<  (flg ? "Yes" : "No") << endl;
    return 0;
}