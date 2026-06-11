#include<cstdio>
#include<cctype>
#include<cstring>

int main(void){
	
	char ch, seq[1200];
	int count[26] = {};
	
	int l = 0;
	while( scanf("%c", &ch) != EOF){
		seq[l] = ch;
		l++;
	}
	
	for(int i= 0;i < strlen(seq); i++){
		if (isalpha(seq[i])){
			seq[i] = tolower(seq[i]);
			int num = seq[i] - 'a';
			count[num] += 1;
		}
	}
	
	for(int j =0; j<26; j++){
		int a = 'a';
		printf("%c : %d\n", a + j , count[ j]);
	}
	
	
	return 0;
}