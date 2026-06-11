//#include <stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define PI 3.14159265359;

class Hoge{
  public:
					long int i0;
	int i1,N0;
	long int D;
					string s0;
					int* iarray0;
					Hoge(int);
					void func0();
					void array0();
	void printarray0();
	~Hoge();
  private:
	
	void inputarray(int*,int);
	void inputarray2(long int*,long int*,int);
	void printarray(int*,int);
	void calcarray(long int*,long int*,int);
	
};


Hoge::Hoge(int itemp){
	
	i0=itemp;
	//cout<<"i0="<<i0<<endl;
	
									}

void Hoge::func0(){
	//cout<<"N0?"<<endl;
	cin>>N0;
	//iarray0=new int[N0];
	//int N1=3;int N2=2;
	cin>>D;
	
	long int* iarray1=new long int[N0];
	long int* iarray2=new long int[N0];

	//inputarray(iarray0,N0);
	//printarray(iarray0,N0);
	inputarray2(iarray1,iarray2,N0);
	//printarray(iarray1,N0);
	//printarray(iarray2,N0);
	
	calcarray(iarray1,iarray2,N0);
	
	delete [] iarray1;
	delete [] iarray2;
	
								}


void Hoge::array0(){

	cout<<"N0?";
	cin>>N0;
	
	
	for (int i0=0;i0<N0;i0++){
		cout<<"i0="<<i0<<endl;
		cin>>iarray0[i0];
		
		
	}
}

void Hoge::inputarray(int* itemp,int itempn){
	
	int* iarray=itemp;
	int n0=itempn;
	for (int i0=0;i0<n0;i0++){
		cout<<"i0="<<i0<<endl;
		cin>>iarray[i0];
	}
}
void Hoge::inputarray2(long int* itemp,long int* itemp2,int itempn){
	
	long int* iarray=itemp;
	long int* iarray2=itemp2;
	int n0=itempn;
	
	for (int i0=0;i0<n0;i0++){
		//cout<<"i0="<<i0<<endl;
		cin>>iarray[i0];
		cin>>iarray2[i0];
	}
}

void Hoge::printarray(int* itemp,int itempn){
	
	int* iarray=itemp;
	int n0=itempn;
	for (int i0=0;i0<n0;i0++){
		cout<<"iarray["<<i0<<"]="<<iarray[i0]<<endl;
	
	}
}

void Hoge::calcarray(long int* itemp1,long int*itemp2,int itempn){
	
	long int* iarray1=itemp1;
	long int* iarray2=itemp2;
	int n0=itempn;
	int nsum0=0;
	for (int i0=0;i0<n0;i0++){
		//cout<<"r^2="<<(iarray1[i0]*iarray1[i0]+iarray2[i0]*iarray2[i0])<<endl;
				if((iarray1[i0]*iarray1[i0]+iarray2[i0]*iarray2[i0])<=(D*D)){nsum0++;}
	}
	//cout<<"nsum0="<<nsum0<<endl;
	cout<<nsum0<<endl;
}


	void Hoge::printarray0(){
							 
							 for (int i0=0;i0<N0;i0++){
			cout<<"iarray0["<<i0<<"]="<<iarray0[i0]<<endl;
										 							 }
}


Hoge::~Hoge(){
	
	//delete [] iarray0;
							}
int main(){
				int N=0;
				//cin>>N;
	Hoge* hoge=new Hoge(N);
	hoge->func0();
	
	return 0;
	delete hoge;
}//end of main