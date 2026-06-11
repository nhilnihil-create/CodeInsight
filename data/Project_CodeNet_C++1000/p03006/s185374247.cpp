#include <bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
using namespace std;

//////全探索したいときに開けよ////////
/*
vector<vector<int>> fspattern;
vector<int> fspattern_draft;
int fspcnt = 0;

void setfspattern_core(int floor,int number,int degree){
  if(floor==degree){
    fspattern.at(fspcnt) = fspattern_draft;
    fspcnt++;
  }else{
    rep(i,number){
      fspattern_draft.at(floor) = i;
      setfspattern_core(floor+1,number,degree);
    }
  }
}

void setfspattern(int number,int degree){
  int64_t array_num = 1;
  rep(i,degree){
    array_num *= number;
  }
  fspattern = vector<vector<int>>(array_num,vector<int>(degree));
  fspattern_draft = vector<int>(degree);
  setfspattern_core(0,number,degree);
}
*/

//////nCrのmodを求めたいときに開けよ/////////
//int64_t univMod = 1000000007;
//int64_t factnum = 100000
//vector<int64_t> modfact(factnum);
//vector<int64_t> modinvfact(factnum);

/*void setmodfact(){
  for(int i=0;i<factnum;i++){
    if(i == 0){
      modfact.at(i) = 1;
    }else{
      modfact.at(i) = (modfact.at(i-1)*i)%univMod;
    }
  }
}

int64_t calcmodpower(int64_t a,int64_t n){
  int64_t res = 1;
  while(n != 0){
    if(n & 1){
      res = (res * a) % univMod;
    }
    a = (a*a) % univMod;
    n = n >> 1;
  }
  return res;
}

int64_t calcinverse(int64_t n){
	return calcmodpower(n,univMod-2);
}

void setmodinvfact(){
  for(int i=0;i<factnum;i++){
    if(i==0){
      modinvfact.at(i) = 1;
    }else{
      modinvfact.at(i) = calcmodpower(modfact.at(i),univMod-2);
    }
  }
}*/


/*
int64_t calcGCD(int64_t a,int64_t b){
	int64_t p = a;
	int64_t q = b;
	int64_t c = a%b;
	while(c != 0){
		p = q;
		q = c;
		c = p%q;
	}
	return q;
}
*/

int main(){
  int n;
  cin >> n;
  vector<pair<int64_t,int64_t>> a(n);
  rep(i,n) cin >> a.at(i).first >> a.at(i).second;
  vector<pair<int64_t,int64_t>> diffa;
  for(int i=0;i< n;i++){
    for(int j=i+1;j<n;j++){
      int64_t diffx = a.at(j).first - a.at(i).first;
      int64_t diffy = a.at(j).second - a.at(i).second;
      if(diffx > 0){
        diffa.push_back(pair<int64_t,int64_t>(diffx,diffy));
      }else if(diffx < 0){
        diffa.push_back(pair<int64_t,int64_t>(-diffx,-diffy));
      }else{
        diffa.push_back(pair<int64_t,int64_t>(0,abs(diffy)));
      }
    }
  }
  sort(diffa.begin(),diffa.end());
  int cnt = 1;
  int maxcnt = 1;
  rep(i,diffa.size()-1){
    //cout << diffa.at(i).first << diffa.at(i).second<<endl; 
    if(diffa.at(i) == diffa.at(i+1)){
      cnt++;
    }else{
      if(maxcnt < cnt){
        maxcnt = cnt;
      }
      cnt = 1;
    }
  }
  if(maxcnt < cnt){
     maxcnt = cnt;
  }
  if(n != 1){
    cout << n-maxcnt << endl;
  }else{
    cout << 1 << endl;
  }
     
}