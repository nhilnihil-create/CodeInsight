#include <bits/stdc++.h>
using namespace std;

int main(){
  int bufN;
  cin >> bufN;

  string N= (bufN%10==0) ? to_string(bufN-1)
                         : to_string(bufN);
  const int lenN= N.size();
  const int Nhead= N.at(0) - '0';
  const int Ntail= N.back()- '0';

  int pat_common= 0;
  int diff= 1;
  for(int len=2; len <= lenN-1; len++){
    pat_common+= diff;
    diff*= 10;
  }

  int Pmiddigit= (lenN > 2) ? 1+ stoi(N.substr(1, lenN-2))
                :(lenN ==2) ? 1
                            : 0;

  auto pattern= [&](int head, int tail){
    int pat_len1= (head==tail && (head <= Nhead || lenN > 1)) ? 1
                                                              : 0;
    int pat_lenN=  (head < Nhead)                  ? diff
                  :(head== Nhead && tail <= Ntail) ? Pmiddigit
                  :(head== Nhead && tail >  Ntail) ? Pmiddigit-1
                                                   : 0;
    int ret= (head==0) ? 0
            :(lenN==1) ? pat_len1
                       : pat_len1+ pat_common+ pat_lenN;
    return ret;
  };

  int ans= 0;
  for(int head=1; head <= 9; head++){
    for(int tail=1; tail <= 9; tail++){
      ans+= pattern(head, tail)* pattern(tail, head);
    }
  }
  
  cout << ans << endl;
}