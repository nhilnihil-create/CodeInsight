/*#include <bits/stdc++.h>
using namespace std;


//Compiler version g++ 6.3.0

int main()
{
   int n = 6;
    vector <string> result;
    
    for(int i = n ; i >= 2; i--){
      
      for (int j = 1; j < i; j++){
        
        if(__gcd(i,j) != 1) continue;
        else{
          
          string s = to_string(j);
          s += "/";
          s += to_string(i);
          result.push_back(s);
          
        }
      }
    }
 for(auto i = result.begin();i != result.end();i++)
{
  
  cout<<*i<<" ";
}*/
  
  /*long long A,B,X;
  
  cin >> A >> B >> X;
  
  long long mm = -1;
  long long x,Y;
  
  for (int i = 1; i <= 10; i++){
    
    Y = B * i;
    long long tmp = X - Y;
    long long t = tmp % A;
    long long maxi = X - t;
    long long hh = tmp / A;
    long long sum = 0,rem;
    while(hh != 0){
      rem = hh % 10;
      hh /= 10;
      sum += 1;
    }
    if(sum >= 10){
      x = 1000000000;
      break;
    }
    if(sum != i) continue;
    if(maxi > mm){
      
      mm = maxi;
      x = tmp / A;
    }
    cout << tmp/A << " "<<maxi <<endl;
    
  }
  if(A == B){
    
  cout << 0;}
  else cout << x;
  return 0;*/
    
 /* int n,m;
  int x;
  map <int,int> mp;
  int L,R,cnt = 0;
  cin >> n >> m;
  vector <int> v(2*m);
  for(int i = 0; i < 2*m; i++){
    cin >> x;
    v[i] = x;
  }
  for(int i = 0; i < 2*m; i++){
    
  }
  
  
  
  for(auto i : mp){
    if(i.second == m)cnt++;
  }
  cout << cnt;*/
    #include <bits/stdc++.h>
using namespace std;
int main(){
  
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(arr,arr+n);
  stack <float> s;
  
  for(int i = n - 1; i >= 0; i--){
    s.push((float)arr[i]);
  }
  for(int i = 0; i < n - 1; i++){
    float a = s.top();
    s.pop();
    float b = s.top();
    s.pop();
    float c = (a+b)/2;
    s.push(c);
  }
  float ans = s.top();
  
  cout << fixed <<setprecision(5) <<ans;
}



  
  
    