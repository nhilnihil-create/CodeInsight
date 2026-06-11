#include <iostream>
#include <string>
#define ll long long
using namespace std;

bool allLettersSame(string s){
  for(char c:s) if(c!=s[0]) return false;
  return true;
}

int main(){
    ll score=0, x=1, n;
    int len, size=1;
    string a;
    cin >> a;
    cin >> n;
    if(allLettersSame(a)){
      cout << n * a.size() / 2 << endl;
      return 0;
    }
    len=a.size()-1;
    for(int i=1; i<=len; i++){
        if(a[i]==a[i-1]){
            size++;
        }
        else{
            score+=size/2;
            size=1;
        }
    }
    score+=size/2;

    int front = 0, back = 0;
    if(a[len]==a[0]){
      for(int i=0; a[i]==a[0]; i++) front++;        
      for(int i=a.size()-1; a[i]==a[0]; i--) back++;
    }
    score*=n;
    if(front%2 == 1 && back%2 == 1){
      score+=(n-1);
    }
    cout << score << endl;
    return 0;
}   