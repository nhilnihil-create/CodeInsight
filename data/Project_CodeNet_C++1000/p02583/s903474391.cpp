#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> s(n);
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  int count = 0;
  if(n<3){
    cout << "0" << endl;
  }else{  
    for(int i=0;i<n;i++){
      for(int j=i;j<n;j++){
        for(int k=j;k<n;k++){
          if(s[i]!=s[j] && s[j]!=s[k] && s[i]!=s[k] && s[i]+s[j]>s[k] && s[j]+s[k]>s[i] && s[k]+s[i]>s[j]){
            count++;
          }
        }
      }
    }
    cout << count << endl;
  }
}
