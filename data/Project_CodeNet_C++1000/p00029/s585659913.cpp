#include <stdio.h>
#include<math.h>
using namespace std;

#define SIZE 1001

int main(){
	char buf[SIZE],longest[33],most_appear[33],tmp[33];
	fgets(buf,SIZE,stdin);
	int max_appear = -1,max_length = -1,tmp_length,tmp_count;

	for(int i=0,k=0;buf[i] != '\0';){	//?§????????????????
		tmp_length = 0;
		tmp_count = 0;
		for(k=i;buf[k] != '\0' && buf[k] != ' ';k++){
			tmp[0+(k-i)] = buf[k];
			tmp_length++;
		}
		if(max_length < tmp_length){ //??????????????´??°
			for(int p=0;p < tmp_length;p++){
				longest[p] = tmp[p];
				longest[p+1] = '\0';
			}
			max_length = tmp_length;
		}
		//??????????????????
		for(int p=0;buf[p] != '\0';){
			int t,match_count=0;
			for(t=0;buf[p+t] != '\0' && buf[p+t] != ' ' && t < tmp_length;t++){
				if(buf[p+t] == tmp[t] || buf[p+t] == tmp[t]-32 ||  buf[p+t] == tmp[t]+32){
					match_count++;
				}
			}
			if(match_count == tmp_length && buf[p+t] == ' ')tmp_count++;
			if(buf[p+t] != '\0'){
				p += (t+1);
			}else{
				break;
			}
		}
		if(max_appear < tmp_count){	//??????????????´??°
			for(int p=0;p < tmp_length;p++){
				most_appear[p] = tmp[p];
				most_appear[p+1] = '\0';
			}
			max_appear = tmp_count;
		}
		if(buf[k] != '\0'){
			i = k+1;
		}else{
			break;
		}
	}

	printf("%s %s\n",most_appear,longest);

    return 0;
}