#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string bottan[]={
    "",
    ".,!? ", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
  };
  int cnt[] = {0,5,3,3,3,3,3,4,3,4};
  
  cin >> n;
  while(n--){
    string str; cin >> str;
    int len = str.size();
    int cnt1=0,cnt2=0;
    for(int i=0;i<len;i++){
      if(str[i] == '0'){
	if(cnt1 != 0){
	  if(cnt2%cnt[cnt1] == 0){
	    cout << bottan[cnt1][cnt[cnt1]-1];
	  }
	  else {
	    cout << bottan[cnt1][cnt2%cnt[cnt1]-1];
	  }
	}
	cnt1 = 0; cnt2 = 0;
      }
      else {
	if(cnt1 == 0){
	  cnt1 = str[i] - '0';
	  cnt2++;
	}
	else {
	  cnt2++;
	}
      }
    }
    cout << endl;
  }
}