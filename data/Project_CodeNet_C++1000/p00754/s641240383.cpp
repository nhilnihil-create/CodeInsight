#include<iostream>
using namespace std;

string s;
int sum1,sum2;

int Search2(int indx);


int Search1(int indx){


  while(indx < (int)s.size()){

    if(s[indx]==']'){
      return -1;
    }

    else if(s[indx]=='('){
      indx = Search1(indx+1);
      sum1++;
      if(indx==-1 ) return -1;
    }

    else if(s[indx]=='['){
      indx = Search2(indx+1);
      sum2++;
      if(indx == -1) return -1;
    }

    else if(s[indx]==')'){
      sum1--;
      return indx;
    }


    indx++;

  }

  return indx;

}

int Search2(int indx){

  while(indx < (int)s.size() ){
    
    if(s[indx]==')'){
      return -1;
    }
    
    else if(s[indx]=='['){
      indx = Search2(indx+1);
      sum2++;
      if(indx==-1) return -1;
    }

    else if(s[indx]=='('){
      indx = Search1(indx+1);
      sum1++;
      if(indx==-1) return -1;
    }

    else if(s[indx] == ']'){
      sum2--;
      return indx;
    }

    indx++;
  }

  return indx;
}





int main(){

  while(getline(cin,s)){

    if(s=="."){ break; }

    sum1= sum2= 0;

    if( Search1(0) == -1 || (sum1!=0 || sum2!=0) )
      cout << "no" << endl;
    else
      cout << "yes" << endl;

  }
  

  return 0;
}