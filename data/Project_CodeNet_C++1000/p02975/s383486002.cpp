#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;

ll arr[100005];

map <ll,int> freq;
int main()
{
    int n;
    cin >> n;
    
    int checker = 0;
    ll a,b,c;
    for (int i = 1; i <= n; i++){
      cin >> arr[i];
      ll f = arr[i];
      if (checker == 0){
        a = f;
        freq[a] = 1;
        checker++;
      }
      else if (checker == 1){
        if (a == f)
          freq[a]++;
        else{
          b = f;
          freq[b]=1;
          checker++;
        }
      }
      else if (checker == 2){
        if (a==f){
          freq[a]++;
        }
        else if (b == f){
          freq[b]++;
        }
        else{
          c = f;
          freq[c] = 1;
          checker++;
        }
      }
      else if (checker == 3){
        if (a==f){
          freq[a]++;
        }
        else if (b == f){
          freq[b]++;
        }
        else if (c==f){
          freq[c]++;
        }
        else{
          checker++;
        }
      }
      else if (checker > 3){
        cout << "No" << endl;
        return 0;
      }
    }

    if (checker == 1){
      if(a == 0 && freq[a] == n){
        cout << "Yes" << endl;
      }
      else{
        cout << "No" << endl;
      }
      return 0;
    }

    if (checker == 2 && n%3 == 0){
      if ((a==0 && freq[a] == n/3 && freq[b] == (2*n)/3)||(b==0 && freq[b] == n/3 && freq[a] == (2*n)/3)){
        cout << "Yes" << endl;
      }
      else 
        cout << "No" << endl;
      return 0;
    }

    if (checker == 3 && n%3 == 0){
      if (freq[a] == freq[b] && freq[c] == freq[b]){
        if ((a^b^c) == 0){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }

    cout << "No" << endl;

    return 0;
}