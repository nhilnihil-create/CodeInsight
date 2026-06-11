#include<iostream>
using namespace std;

int main()
{
int W;int H;int x;int y;int r;
	cin >> W;
	if(W<0||W>100){
	cout << "error" << endl;
       return 0;
	}
     cin >> H;
     if(H<0||H>100){
     cout << "error" << endl;
       return 0;
	}
     cin >> x;
	if(x<-100||x>100){
     cout << "error"<< endl;
       return 0;
	}
     cin >> y;
	if(y<-100||y>100){
     cout << "error" << endl;
       return 0;
	}
     cin >> r;
     if(r<0||r>100){
     cout << "error" << endl;
       return 0;
	}
       if(x-r<0||x+r>W){
	cout << "No" << endl;
       return 0;
	}else if(y-r<0||y+r>H){
       cout << "No" << endl;
       return 0;
       }else{
       cout << "Yes" << endl;
       return 0;
}
return 0;
}