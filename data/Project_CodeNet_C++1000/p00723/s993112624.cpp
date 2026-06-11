#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
using namespace std;

struct Info{
	char regular[100];
};

bool strCmp(char* base, char* comp){
	int length1 = 0,length2 = 0;
	for(int i=0;base[i] != '\0'; i++)length1++;
	for(int i=0;comp[i] != '\0'; i++)length2++;
	if(length1 != length2)return false;

	for(int i=0;base[i] != '\0'; i++){
		if(base[i] != comp[i])return false;
	}
	return true;
}

void strcpy(char* to,char* str){
	for(int i=0;str[i] != '\0';i++){
		to[i] = str[i];
		to[i+1] = '\0';
	}
}

void func(){

	char buf[100];
	scanf("%s",buf);

	Info info[1000];
	strcpy(info[0].regular,buf);

	int info_index = 1;

	int length;
	for(length = 0;buf[length] != '\0';length++);

	char Rev_norm_norm[100],norm_rev[100],Rev_norm_rev[100],rev_norm[100],Rev_rev_norm[100],rev_rev[100],Rev_rev_rev[100];

	bool FLG;

	for(int div = 0; div <= length -2; div++){ //div????????????div???????????¨?????????????????????

		//Rev_norm_norm
		for(int k = 0; k <= div; k++){
			Rev_norm_norm[length-1-div+k] = buf[k];
			norm_rev[k] = buf[k];
			Rev_norm_rev[length-1-div+k] = norm_rev[k];
			rev_norm[k] = buf[div-k];
			Rev_rev_norm[length-1-div+k] = rev_norm[k];
			rev_rev[k] = buf[div-k];
			Rev_rev_rev[length-1-div+k] = rev_rev[k];
		}
		for(int k = div+1; k <= length-1; k++){
			Rev_norm_norm[k-(div+1)] = buf[k];
			norm_rev[k] = buf[length-1-(k-(div+1))];
			Rev_norm_rev[k-(div+1)] = norm_rev[k];
			rev_norm[k] = buf[k];
			Rev_rev_norm[k-(div+1)] = rev_norm[k];
			rev_rev[k] = buf[length-1-(k-(div+1))];
			Rev_rev_rev[k-(div+1)] = rev_rev[k];
		}
		Rev_norm_norm[length] = '\0';
		norm_rev[length] = '\0';
		Rev_norm_rev[length] = '\0';
		rev_norm[length] = '\0';
		Rev_rev_norm[length] = '\0';
		rev_rev[length] = '\0';
		Rev_rev_rev[length] = '\0';

		//printf("Rev_norm_norm:%s\n",Rev_norm_norm);

		FLG = true;
		for(int k = 0; k < info_index; k++){
			if(strCmp(info[k].regular,Rev_norm_norm)){
				FLG = false;
				break;
			}
		}

		if(FLG){
			strcpy(info[info_index].regular,Rev_norm_norm);
			info_index++;
		}
		//printf("norm_rev:%s Rev_norm_rev:%s\n",norm_rev,Rev_norm_rev);

		//norm_rev
		FLG = true;
		for(int k = 0; k < info_index; k++){
			if(strCmp(info[k].regular,norm_rev)){
				FLG = false;
				break;
			}
		}

		if(FLG){
			strcpy(info[info_index].regular,norm_rev);
			info_index++;
		}

		//Rev_norm_rev
		FLG = true;
		for(int k = 0; k < info_index; k++){
			if(strCmp(info[k].regular,Rev_norm_rev)){
				FLG = false;
				break;
			}
		}

		if(FLG){
			strcpy(info[info_index].regular,Rev_norm_rev);
			info_index++;
		}


		//-------------------------------------------------------------------------------------------

		//printf("rev_norm:%s Rev_rev_norm:%s\n",rev_norm,Rev_rev_norm);

		//rev_norm
		FLG = true;
		for(int k = 0; k < info_index; k++){
			if(strCmp(info[k].regular,rev_norm)){
				FLG = false;
				break;
			}
		}

		if(FLG){
			strcpy(info[info_index].regular,rev_norm);
			info_index++;
		}

		//Rev_rev_norm
		FLG = true;
		for(int k = 0; k < info_index; k++){
			if(strCmp(info[k].regular,Rev_rev_norm)){
				FLG = false;
				break;
			}
		}

		if(FLG){
			strcpy(info[info_index].regular,Rev_rev_norm);
			info_index++;
		}


		//-------------------------------------------------------------------------------------------
		//printf("rev_rev:%s Rev_rev_rev:%s\n",rev_rev,Rev_rev_rev);

		//rev_rev
		FLG = true;
		for(int k = 0; k < info_index; k++){
			if(strCmp(info[k].regular,rev_rev)){
				FLG = false;
				break;
			}
		}

		if(FLG){
			strcpy(info[info_index].regular,rev_rev);
			info_index++;
		}

		//Rev_rev_rev
		FLG = true;
		for(int k = 0; k < info_index; k++){
			if(strCmp(info[k].regular,Rev_rev_rev)){
				FLG = false;
				break;
			}
		}

		if(FLG){
			strcpy(info[info_index].regular,Rev_rev_rev);
			info_index++;
		}
	}

	printf("%d\n",info_index);
}

int main(){

	int N;
	scanf("%d",&N);

	for(int i = 0; i < N; i++){
		func();
	}

	return 0;
}