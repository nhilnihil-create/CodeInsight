#include<iostream>

using namespace std;

#define WIDTH 5
#define MAX_HEIGHT 10
#define CHAIN_SIZE 3
#define EXTINCT -1//?¶?????????????
#define EMPTY -2//???????????¨?????????

void down(int h,  int stones[MAX_HEIGHT][WIDTH]){

  for(int i=0;i<h;i++){
    for(int j=0;j<WIDTH;j++){
      if(stones[i][j] == EXTINCT){
	int c;
	for(c=i; c<h-1; c++){
	  if(stones[c+1][j] == EMPTY){
	    break;
	  }	  
	  stones[c][j] = stones[c+1][j];
	}

	while(c<h){
	  stones[c][j] = EMPTY;
	  c++;
	}
      }
      
      if(stones[i][j] == EXTINCT){
	//???????????¨???????????????????????????EXTINCT?????£????????????????????????
	i--;
      }
    }
  }
  
}

int main(){
  int h;
  int stones[MAX_HEIGHT][WIDTH];
  cin>>h;

  while(h != 0){
    int ans = 0;
    for(int i=h-1;i>=0;i--){
      for(int j=0;j<WIDTH;j++){
	cin>>stones[i][j];
      }
    }


    bool finish = false;

    while(!finish){
       
      bool chained = false;
      for(int i=0;i<h;i++){
	int s = 0;
	int e = 0;
	for(int j=0;j<WIDTH-1;j++){
	  if(stones[i][j]==stones[i][j+1] && stones[i][j]!=EXTINCT && stones[i][j]!=EMPTY){
	    e++;
	    if(e-s+1 >= CHAIN_SIZE){//3??\????????£?¶??????????
	      int num = stones[i][s];
	      int c = 0;
	      chained = true;
	      while(s<WIDTH && stones[i][s] == num){
		stones[i][s] = EXTINCT;
		s++;
		c++;
	      }
	      ans += c*num;
	      e=s;
	    }
	  }else{
	    s = j+1;
	    e = j+1;
	  }
	}
	
      }

      down(h,stones);
      
      if(!chained){
	finish = true;
      }
    }
    
    cout<<ans<<endl;
    cin>>h;
  }
  

  return 0;
}