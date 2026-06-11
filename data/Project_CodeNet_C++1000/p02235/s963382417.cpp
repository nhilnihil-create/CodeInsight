#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(void){
  string st1, st2;
  int q, val[1001][1001];

  cin >> q;

  for(int i=0; i<q; i++){
    cin>>st1;
    cin>>st2;

    for(int j=0; j<=st1.length(); j++){
      for(int k=0; k<=st2.length(); k++){

	if(j==0 || k==0) val[j][k] = 0;
	else{
	  if(val[j-1][k] == min(st1.length(), st2.length())){
	    val[j][k] = st1.length();
	  }else{

	    if(st1[j-1] == st2[k-1]){
	      val[j][k] = val[j-1][k-1]+1;
	    }else{
	      val[j][k] = max(val[j-1][k], val[j][k-1]);
	    }
	  }
	}
      }
    }

    /*
      for(int j=0; j<=st1.length(); j++){
      for(int k=0; k<=st2.length(); k++){
      cout << val[j][k] << " ";
      }
      cout << "\n";
      }
    */

    cout << val[st1.length()][st2.length()] << "\n";
  }

  return 0;
}

