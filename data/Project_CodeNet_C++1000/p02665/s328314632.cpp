#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string>split(string s, char delim){
  int len = s.length();
  string currStr = "";
  vector<string>retVec;
  for(int i = 0;i<len;i++){
    char ch = s[i];
    if(ch==delim){
      retVec.push_back(currStr);
      currStr = "";
    }else{
      currStr += ch;
    }
  }
  retVec.push_back(currStr);
  return retVec;
}



vector<int>strToIntVec(string s){
  int len = s.length();
  //  s = s.substr(1,len-2);
    vector<string>strVec = split(s,' ');
  vector<int>retVec;
  for(int i=0;i<(int)strVec.size();i++){
    int el = atoi(strVec[i].c_str());
    retVec.push_back(el);
  }
  return retVec;
}

class BinTree{
public:
  long long getNInner(long long nNodes, int parDepth,int nLeaves){
    int minDepth = 0;
    int nOnes = 0;
    /*    while(nNodes>0LL){
      if(nNodes%2==1LL){
	nOnes++;
      }
      minDepth++;
      nNodes = nNodes>>1;
      }*/
    long long possNodes = 1LL;
    long long retV = -1LL;
    for(int i=0;i<parDepth;i++){
      possNodes = possNodes<<1LL;
      if(possNodes>(nNodes+nLeaves)){
	retV = nNodes;
	break;
      }
    }
    if(retV<0){
      retV = min(possNodes-nLeaves,nNodes);
    }
    return retV;
  }
  //leaves and non-leaves
  long long sumNonLvs(unordered_map<int,long long>&lNonLvs,vector<int>&aVec){
    long long sum = 0LL;
    unordered_map<int,long long>::iterator it;
    for(it=lNonLvs.begin();it!=lNonLvs.end();it++){
      sum += (it->second+aVec[it->first]);
    }
    return sum;
  }

  void getLMaxNonLvs(int n, vector<int>&aVec,unordered_map<int,long long>&lMaxNonLvs,bool&err){
    long long sumA = sumVec(aVec);
    for(int i=0;i<=n;i++){
      sumA -= aVec[i];
      if(i==0){
	if(aVec[i]>1){
	  err = true;
	  break;
	}else{
	  long long maxV = 1LL-aVec[i];
	  maxV = min(maxV,sumA);
	  lMaxNonLvs[i] = maxV;
	}
      }else{
	//long long maxPoss = 1LL<<i;
	/*if(aVec[i]>maxPoss){
	  err = true;
	  break;
	  }*/
	long long maxV = 2LL*lMaxNonLvs[i-1]-aVec[i];
	maxV = min(maxV,sumA);	
	if(maxV<0LL){
	  err = true;
	  break;
	}
	//maxV = min(maxV,maxPoss-aVec[i]);
	lMaxNonLvs[i] = maxV;
      }
      //cout<<"getLmaxNonLvs, i "<<i<<", lMaxNonLvs "<<lMaxNonLvs[i]<<endl;
    }
  }

  long long sumVec(vector<int>&vec){
    long long sum = 0LL;
    for(int i=0;i<vec.size();i++){
      sum += (long long)vec[i];
    }
    return sum;
  }
  void getLNonLvs(int n, vector<int>&aVec,unordered_map<int,long long>&lMaxNonLvs,unordered_map<int,long long>&lNonLvs,bool&err){
    for(int i=n;i>=0;i--){
      if(i==n){
	if(aVec[i]==0){
	  err = true;
	  break;
	}
	lNonLvs[i] = 0LL;
      }else{
	long long minV = (lNonLvs[i+1]+aVec[i+1])/2LL;
	if(((lNonLvs[i+1]+aVec[i+1])%2LL)==1LL){
	  minV++;
	}
	//	long long maxV = (1LL<<i)-aVec[i];
	//	long long maxV = lMaxNonLvs[i];
	//if(i>0){
	// maxV = min(maxV,2LL*lMaxNonLvs[i-1]-aVec[i]);
	//}
	long long maxV = min(lMaxNonLvs[i],lNonLvs[i+1]+aVec[i+1]);
	if(minV>maxV){
	  err = true;
	  break;
	}
	lNonLvs[i] = maxV;
      }
      //      cout<<"getLNonLvs, i "<<i<<", lNonLvs "<<lNonLvs[i]<<endl;      
    }
  }
  
  long long getMaxNodes(int n, vector<int>aVec){
    unordered_map<int,long long>lMaxNonLvs;
    unordered_map<int,long long>lNonLvs;
    bool err = false;
    long long retV = 0LL;
    getLMaxNonLvs(n,aVec,lMaxNonLvs,err);
    if(err){
      retV = -1LL;
    }else{
      getLNonLvs(n,aVec,lMaxNonLvs,lNonLvs,err);
      if(err){
	retV = -1LL;
      }else{
	retV = sumNonLvs(lNonLvs,aVec);
      }
    }
    return retV;
  }
  
};

int main(int argc,const char*argv[]){
  BinTree bt;
  string nLn,aLn;
  getline(cin,nLn);
  getline(cin,aLn);
  int n = atoi(nLn.c_str());
  vector<int>aVec = strToIntVec(aLn);
  long long maxN = bt.getMaxNodes(n,aVec);
  cout<<maxN<<endl;
  return 0;
}
