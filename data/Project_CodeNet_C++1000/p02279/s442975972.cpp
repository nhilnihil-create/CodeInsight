#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
   
int main(){
  int n,id=1,nv,ch,index,syuryo=1;
     
  scanf("%d\n",&n);
 
  int *A = new int[100040];
  bool *B = new bool[100040];
  int *C = new int[100040];
  string *D = new string[100040];
  int st,ed;
  for(int i=0;i<=100040;i++){
    A[i]=0; // hukasa
    C[i]=-1; // oya
    B[i]=false; //false nara ko wo motte inai
  }
  for(int i=0;i<n;i++){
    scanf("%d",&id);
    
    getline(cin,D[id]);
 
    syuryo=1;
    for(int r=1;r<=D[id].length();r++){
      if(D[id][r] == ' '){
	syuryo = r-1; // String no iti gime
	break;
      }
    }
   
    index = atoi(D[id].substr(1,syuryo).c_str()); // val wo motomeru 
    //cout << "index = " << index << ", syuryo = " << syuryo << endl;

    if(index != 0)B[id]=true;
       
   

    if(index != 0){
      st = syuryo+2;    
      for(int d = syuryo+2;d<=D[id].length();d++){ 
	if(D[id][d] == ' ' || d == D[id].length()){
	  A[atoi(D[id].substr(st,d-st).c_str())]=A[id]+1;
	  C[atoi(D[id].substr(st,d-st).c_str())]=id;
	  if(B[atoi(D[id].substr(st,d-st).c_str())]){
	    int st2=3;
	    
	    for(int j = syuryo+2;j<=D[atoi(D[id].substr(st,d-st).c_str())].length();j++){
	      
	      if(D[atoi(D[id].substr(st,d-st).c_str())][j] == ' ' || j == D[atoi(D[id].substr(st,d-st).c_str())].length()){
		A[atoi(D[atoi(D[id].substr(st,d-st).c_str())].substr(st2,j-st2).c_str())]=A[atoi(D[id].substr(st,d-st).c_str())]+1;
		st2=j+1;
	      }
	    }
	  }
	  st = d+1;
      }
      }
      
    }
    
  }
     
 
     
  for(int i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,C[i],A[i]);
    int cou=0;
    if(C[i] == -1){printf("root, [");}
    else if(!B[i])printf("leaf, [");
    else printf("internal node, [");
    

    syuryo=1;
    for(int r=1;r<=D[i].length();r++){
      if(D[i][r] == ' '){
	syuryo = r-1;
	break;
      }
    }
    index = atoi(D[i].substr(1,syuryo).c_str());
    //cout  << endl << index << endl;
    
    st=syuryo+2;
    if(index != 0){      
      for(int j=syuryo+2;j<=D[i].length();j++){
	if(D[i][j] == ' ' || D[i].length() == j ){
	  //cout << "i = " << i << ",j = " << j << endl;qqq
	  printf("%d",atoi(D[i].substr(st,j-st).c_str()));
	  if(j != D[i].length())printf(", ");
	  st=j+1;
	}
      }
    }
    printf("]\n");
  }
     
  delete [] A;
  delete [] B;
  delete [] C;
  delete [] D;
  return 0;
}