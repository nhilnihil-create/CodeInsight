#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Word {
public:
	char w[33];
	int length;
	int freq;
public:	
	Word() {
		strcpy(w, "");
		length = 0;
		freq = 0;
	}
};

int main()
{
	char str[1001];
	char buf[32];
	char *p, *q;
	fgets(str, 1001, stdin);
	
	Word wl[32];
	
	for ( p = str; (q = strstr(p, " ")) != NULL; ) {
		*q = '\0'; strcpy(buf, p); 
		for (int i=0; i<32; i++) {
			if ( strcmp(wl[i].w, "") == 0 ) {
				strcpy(wl[i].w, buf);
				wl[i].length = strlen(buf);
				wl[i].freq = 1;
				break;
			}
			else if ( strcmp(wl[i].w, buf) == 0 ) {
				wl[i].freq++;
				break;
			}
		}
		p = q + 1;
	}
	
	strcpy(buf, p); 
	for (int i=0; i<32; i++) {
		if ( strcmp(wl[i].w, "") == 0 ) {
			strcpy(wl[i].w, buf);
			wl[i].length = strlen(buf);
			wl[i].freq = 1;
			break;
		}
		else if ( strcmp(wl[i].w, buf) == 0 ) {
			wl[i].freq++;
			break;
		}
	}

	
	int max_freq = 0;
	int max_length = 0;
	char max_freq_w[32];
	char max_length_w[32];
	
	for (int i=0; i<32; i++) {
		if (max_freq < wl[i].freq) {
			max_freq = wl[i].freq;
			strcpy(max_freq_w, wl[i].w);
		}
		if (max_length < wl[i].length) {
			max_length = wl[i].length;
			strcpy(max_length_w, wl[i].w);
		}
	}
	
	cout << max_freq_w << " " << max_length_w << endl;
	
	return 0;
}