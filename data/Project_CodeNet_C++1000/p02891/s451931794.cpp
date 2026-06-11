# include <iostream>
# include <string>
using namespace std;
typedef long long ll;

bool allCharSame(string s){
  char c = s[0];
  for(int i=1; i<s.size(); i++) if(s[i] != c) return false;
  return true;
}

int main(){
  string s;
  ll k;

  cin >> s >> k;
  if(allCharSame(s)){
    cout << s.size() * k / 2 << endl;
  }
  else{
    ll front = 0;
    while(s[front] == s[front+1]) front++;
    front++;

    ll back = s.size()-1;
    while(s[back] == s[back-1]) back--;
    back = s.size()-back;

    ll ans = 0;
    if(s[0] == s[s.size()-1]) {
      ans += (front+back)/2 * (k-1);
    }
    else {
      ans += ((front/2) + (back/2)) * (k-1);
    }
    ans += (front/2) + (back/2);

    ll left = front;
    ll right = left;
    while(left < s.size()-back){
      while(right + 1 < s.size()-back && s[left] == s[right+1]) right++;
      ans += ((right-left+1)/2)*k;
      left = right+1;
      right = left;
    }

    cout << ans << endl;
  }
  return 0;
}