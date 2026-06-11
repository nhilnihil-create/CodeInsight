/*************************************************************************
    > File Name: aoj0033.cpp
    > Author:    WArobot 
    > Blog:      http://www.cnblogs.com/WArobot/ 
    > Created Time: 2017??´06???21??\ ????????? 19??¶29???08?§?
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n , ball[10] , left_back , last_lb , right_back , last_rb ;
bool ok;

void DFS(int num){
	if( ok || num > 10 )	return;
	if( num == 10 ){
		ok = true;	return;
	}
	if( ball[num] >= left_back ){
		last_lb = left_back;
		left_back = ball[num];
		DFS(num+1);	
		left_back = last_lb;
	}
	if( ball[num] >= right_back ){
		last_rb = right_back;
		right_back = ball[num];
		DFS(num+1);	
		right_back = last_rb;
	}
}
int main(){
	scanf("%d",&n);
	while(n--){
		for(int i = 0 ; i < 10 ; i++){
			scanf("%d",&ball[i]);
		}
		ok = false;	left_back = right_back = last_lb = last_rb = 0;
		DFS(0);
		if(ok)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}