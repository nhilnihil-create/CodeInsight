#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,x,y) for(int (i)=(x);(i)<(y);(i)++)

int main()
{
  while(true){
    int n;
    cin>>n;
    if(n==0){
      break;
    }

    vector<int> vec;
    rep(i,0,300000){
      vec.push_back(i);
    }

    vec[1]=0;
    rep(i,0,300000){
      if(vec[i]!=0){
        for(int j=i+i;j<300000;j+=i){
          vec[j]=0;
        }
      }
    }
    vector<int> vec2;
    rep(i,0,300000){
      if(vec[i]!=0){
        vec2.push_back(i);
      }
    }

    int count=0;
    rep(i,0,vec2.size()){
      if(vec2[i]>2*n){
        break;
      }
      if(vec2[i]>n){
        count++;
      }
    }
    cout<<count<<endl;
  }

  return 0;
}